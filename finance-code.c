#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100
#define MAX_HEAP_SIZE 100

// Linked List (Transaction History)
typedef struct Transaction {
    char type[10]; 
    char description[100];
    double amount;
    struct Transaction* next;
} Transaction;

// Stack (Undo/Redo)
typedef struct Action {
    char operation[50];
    struct Action* next;
} Action;

// Queue (Recurring Payments)
typedef struct RecurringPayment {
    char description[100];
    double amount;
    struct RecurringPayment* next;
} RecurringPayment;

// Hashmap (Budget Categories)
typedef struct Budget {
    char category[50];
    double total;
    struct Budget* next;
} Budget;

// Heap (Investment Portfolio)
typedef struct Investment {
    char name[50];
    double performance;
} Investment;

// Binary Search Tree (Savings Goals)
typedef struct Goal {
    char name[50];
    double amount;
    struct Goal* left;
    struct Goal* right;
} Goal;

// Global structures
Transaction* transactionHead = NULL;
Action* undoStack = NULL;
RecurringPayment* queueFront = NULL;
RecurringPayment* queueRear = NULL;
Budget* budgetTable[HASH_SIZE] = {NULL};
Investment investmentHeap[MAX_HEAP_SIZE];
int heapSize = 0;
Goal* goalRoot = NULL;

// Hash Function
int hash(const char* key) {
    int hash = 0;
    for (int i = 0; key[i]; i++) hash = (hash + key[i]) % HASH_SIZE;
    return hash;
}

// Linked List Operations
void addTransaction(const char* type, const char* description, double amount) {
    Transaction* newTransaction = (Transaction*)malloc(sizeof(Transaction));
    strcpy(newTransaction->type, type);
    strcpy(newTransaction->description, description);
    newTransaction->amount = amount;
    newTransaction->next = transactionHead;
    transactionHead = newTransaction;

    printf("Transaction added: %s - %s - %.2f\n", type, description, amount);
}

// Stack Operations
void pushAction(Action** stack, const char* operation) {
    Action* newAction = (Action*)malloc(sizeof(Action));
    strcpy(newAction->operation, operation);
    newAction->next = *stack;
    *stack = newAction;
}
void popAction(Action** stack) {
    if (*stack == NULL) return;
    Action* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}

// Queue Operations
void enqueueRecurring(const char* description, double amount) {
    RecurringPayment* newPayment = (RecurringPayment*)malloc(sizeof(RecurringPayment));
    strcpy(newPayment->description, description);
    newPayment->amount = amount;
    newPayment->next = NULL;

    if (queueRear == NULL) {
        queueFront = queueRear = newPayment;
    } else {
        queueRear->next = newPayment;
        queueRear = newPayment;
    }
    printf("Recurring payment added: %s - %.2f\n", description, amount);
}
void dequeueRecurring() {
    if (queueFront == NULL) return;
    RecurringPayment* temp = queueFront;
    queueFront = queueFront->next;
    if (queueFront == NULL) queueRear = NULL;
    printf("Recurring payment processed: %s - %.2f\n", temp->description, temp->amount);
    free(temp);
}

// Hashmap Operations
void updateBudget(const char* category, double amount) {
    int idx = hash(category);
    Budget* entry = budgetTable[idx];
    while (entry) {
        if (strcmp(entry->category, category) == 0) {
            entry->total += amount;
            printf("Updated category %s: %.2f\n", category, entry->total);
            return;
        }
        entry = entry->next;
    }
    Budget* newBudget = (Budget*)malloc(sizeof(Budget));
    strcpy(newBudget->category, category);
    newBudget->total = amount;
    newBudget->next = budgetTable[idx];
    budgetTable[idx] = newBudget;
    printf("Added new category %s: %.2f\n", category, amount);
}

// Heap Operations
void insertInvestment(const char* name, double performance) {
    if (heapSize >= MAX_HEAP_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    Investment newInvestment;
    strcpy(newInvestment.name, name);
    newInvestment.performance = performance;
    investmentHeap[heapSize] = newInvestment;

    int i = heapSize++;
    while (i > 0 && investmentHeap[(i - 1) / 2].performance < investmentHeap[i].performance) {
        Investment temp = investmentHeap[(i - 1) / 2];
        investmentHeap[(i - 1) / 2] = investmentHeap[i];
        investmentHeap[i] = temp;
        i = (i - 1) / 2;
    }
    printf("Investment added: %s - %.2f\n", name, performance);
}

// BST Operations
Goal* addGoal(Goal* root, const char* name, double amount) {
    if (root == NULL) {
        Goal* newGoal = (Goal*)malloc(sizeof(Goal));
        strcpy(newGoal->name, name);
        newGoal->amount = amount;
        newGoal->left = newGoal->right = NULL;
        return newGoal;
    }
    if (amount < root->amount) root->left = addGoal(root->left, name, amount);
    else root->right = addGoal(root->right, name, amount);
    return root;
}
void displayGoals(Goal* root) {
    if (root == NULL) return;
    displayGoals(root->left);
    printf("Goal: %s - %.2f\n", root->name, root->amount);
    displayGoals(root->right);
}

// Main Function
int main() {
    addTransaction("Income", "Salary", 1000.0);
    addTransaction("Expense", "Groceries", -200.0);

    pushAction(&undoStack, "Added Income: Salary");
    pushAction(&undoStack, "Added Expense: Groceries");

    enqueueRecurring("Netflix", 15.0);
    dequeueRecurring();

    updateBudget("Food", -200.0);
    updateBudget("Entertainment", -15.0);

    insertInvestment("Stock A", 8.5);
    insertInvestment("Stock B", 9.2);

    goalRoot = addGoal(goalRoot, "Buy a car", 5000.0);
    goalRoot = addGoal(goalRoot, "Vacation", 2000.0);

    printf("\nSavings Goals:\n");
    displayGoals(goalRoot);

    return 0;
}
