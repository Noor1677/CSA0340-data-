#include <stdio.h>
#include <stdbool.h>
#define TABLE_SIZE 10
struct HashTable {
    int keys[TABLE_SIZE];
    int values[TABLE_SIZE];
};
void initialize(struct HashTable* table) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table->keys[i] = -1;
        table->values[i] = -1;
    }
}
int hash(int key) {
    return key % TABLE_SIZE;
}
void insert(struct HashTable* table, int key, int value) {
    int index = hash(key);
    while (table->keys[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
          }
    table->keys[index] = key;
    table->values[index] = value;
}
int search(struct HashTable* table, int key) {
    int index = hash(key);
    while (table->keys[index] != -1) {
        if (table->keys[index] == key) {
            return table->values[index];
          }
        index = (index + 1) % TABLE_SIZE;
    }
    return -1;
}
int main() {
    struct HashTable table;
    initialize(&table);
    insert(&table, 5, 50);
    insert(&table, 15, 150);
    insert(&table, 25, 250);
    insert(&table, 6, 60);
    printf("Value at key 15: %d\n", search(&table, 15));
    printf("Value at key 5: %d\n", search(&table, 5));
    printf("Value at key 25: %d\n", search(&table, 25));
    printf("Value at key 6: %d\n", search(&table, 6));
    printf("Value at key 10: %d\n", search(&table, 10));
    return 0;
}
