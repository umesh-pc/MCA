#include <stdio.h>

#define MAX 100

int parent[MAX];

// Create sets: initialize each element as its own parent (leader)
void create(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// Find the leader of the set that element x belongs to
int find(int x) {
    if (parent[x] == x) {
        return x;  // x is leader of itself
    } else {
        return find(parent[x]);  // recursively find leader
    }
}

// Union two sets by connecting their leaders
void union_sets(int a, int b) {
    int leaderA = find(a);
    int leaderB = find(b);

    if (leaderA != leaderB) {
        parent[leaderB] = leaderA;  // Merge: make leaderA the leader of leaderB
    }
}

int main() {
    int n = 5,x,y,z,i; // Number of elements (0 to 4)

    create(n);  // Initialize the disjoint sets
     printf("no of union operations");
    scanf("%d",&z);
    // Merge some sets
    for(i=1;i<=z;i++){
     printf("enter two elements to union");
    scanf("%d %d",&x,&y);
    union_sets(x, y);}
    printf("enter two elements to find if they are in same group");
    scanf("%d %d",&x,&y);

    // Check if 1 and 0 belong to the same set
    if (find(x) == find(y)) {
        printf("Person %d and %d are in the same group\n",x,y);
    } else {
        printf("Person %d and %d are NOT in the same group\n",x,y);
    }

   

    return 0;
}
