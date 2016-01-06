#include <stdio.h>
#include <string.h>

#define MaxCandidates 7
#define MaxNameLength 30
#define MaxNameBuffer MaxNameLength + 1

typedef struct {
	unsigned short id;
	char name[MaxNameBuffer];
	unsigned int votes;
} Candidate;

typedef struct {
	unsigned int valid, spoil;
} VoteCount;

void initialize(Candidate candidates[], FILE *in) {
	char lastName[MaxNameBuffer] = "";
	unsigned short counter = 0;
	while (strcmp(lastName,"\n") != 0) {
		fgets(lastName, sizeof(lastName), in);
		candidates[counter].id = counter + 1;
		strncpy(candidates[counter].name, lastName, strlen(lastName) - 1);
		candidates[counter].votes = 0;
		counter++;
	}
}

VoteCount processVotes(Candidate candidates[], FILE *in, FILE *out) {
	VoteCount voteCount;
	voteCount.valid = voteCount.spoil = 0;
	
	unsigned int v = -1;
	while (1) {
		fscanf(in, "%d", &v);
		if (v == 0) {
			break;
		} else if (v < 1 || v > MaxCandidates)  {
			// invalid vote
			voteCount.spoil++;
			fprintf(out, "Invalid vote: %d\n", v);
		} else {
			// valid vote
			candidates[v-1].votes++;
			voteCount.valid++;
		}
	}

	fprintf(out, "\n");
	return voteCount;
}

unsigned int getBestVoted(Candidate candidates[]) {
	unsigned int best = 0;
	for (unsigned int i = 0; i < MaxCandidates; i++) {
		if (candidates[i].votes > best) {
			best = candidates[i].votes;
		}
	}
	return best;
}

void printScores(Candidate candidates[], FILE *out) {
	for (unsigned int i = 0; i < MaxCandidates; i++) {
		fprintf(out, "%s\t%d\n", candidates[i].name, candidates[i].votes);
	}
}

void sortByVote(Candidate candidates[]) {
	Candidate insertItem;
	for (unsigned int i = 1; i < MaxCandidates + 1; i++) {
		insertItem = candidates[i];
		int k = i - 1;
		while (k >= 0 && insertItem.votes > candidates[i].votes) {
			candidates[k + 1] = candidates[k];
			--k;
		}
		candidates[k + 1] = insertItem;
	}
}

void printResults(Candidate candidates[], VoteCount count, FILE *out) {
	fprintf(out, "Number of voters: %d\n", count.valid + count.spoil);
	fprintf(out, "Number of valid votes: %d\n", count.valid);
	fprintf(out, "number of spoilt votes: %d\n", count.spoil);

	fprintf(out, "\nCandidate\tScore\n");
	printScores(candidates, out);

	fprintf(out, "\nThe winner(s):\n");
	unsigned int bestVote = getBestVoted(candidates);
	for (unsigned int i = 0; i < MaxCandidates; i++) {
		if (candidates[i].votes == bestVote) {
			fprintf(out, "%s\n", candidates[i].name);
		}
	}

	fprintf(out, "\nSorted results\nCandidate\tScore\n");
	sortByVote(candidates);
	printScores(candidates, out);
}

int main(int argc, char const *argv[]) {
	if (argc != 3) {
		printf("Usage: %s input output\n", argv[0]);
		return 1;
	}

	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w");

	Candidate candidates[MaxCandidates];

	initialize(candidates, in);
	VoteCount count = processVotes(candidates, in, out);
	printf("Valid %d\nInvalid: %d\n", count.valid, count.spoil);
	printResults(candidates, count, out);

	fclose(in);
	fclose(out);

	return 0;
}
