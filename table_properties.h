#ifndef TABLE_PROPERTIES_HEADER_GUARD
#define TABLE_PROPERTIES_HEADER_GUARD

#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define COLUMN_USERNAME_SIZE 32
#define COLUMN_EMAIL_SIZE 255

// Our table will only store this data structure FOR NOW.
typedef struct {
  uint32_t id;
  char username[COLUMN_USERNAME_SIZE];
  char email[COLUMN_EMAIL_SIZE];
}Row;

#define size_of_attribute(StructPtr, Attribute) sizeof(((StructPtr*)0)->Attribute)
// These are interesting ways to call functions.
static const uint32_t ID_SIZE = size_of_attribute(Row, id);
static const uint32_t USERNAME_SIZE = size_of_attribute(Row, username);
static const uint32_t EMAIL_SIZE = size_of_attribute(Row, email);

static const uint32_t ID_OFFSET = 0;
static const uint32_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
static const uint32_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;

static const uint32_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;
static const uint32_t PAGE_SIZE = 4096;
#define TABLE_MAX_PAGES 100

static const uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
static const uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

typedef struct{
  uint32_t num_rows;
  void* pages[TABLE_MAX_PAGES]; // store all page-pointer here, because we store table in the memory in the form of pages.
} Table;

Table* new_table();
void free_table(Table* );
// Add row to the table
void serialize_row(Row* , void* );
// Get row from the table so that we can work on it.
void deserialize_row(void* , Row* );
// Finds/searches memory address for a row number. Meaning we can access elements with row number!
void* row_slot(Table* , uint32_t);
void print_row(Row* );

#endif
