#include "table_properties.h"

Table* new_table(){
  Table* table = (Table*)malloc(sizeof(Table));
  table->num_rows = 0;
  for(uint32_t i=0; i<TABLE_MAX_PAGES; i++){
    table->pages[i]=NULL;
  }
  return table;
}

void free_table(Table* table){
  // We initialize them with NULL, so finding a NULL page means we stop freeingallocated memory for pages.
  for(uint32_t i=0; table->pages[i]; i++){
    free(table->pages[i]);
  }
  free(table);
}

void* row_slot(Table* table, uint32_t row_num){
  uint32_t page_num = row_num / ROWS_PER_PAGE;
  void* page = table->pages[page_num];
  if(page==NULL){
    // make a new page
    page = table->pages[page_num] = malloc(PAGE_SIZE);
  }
  // remainder = number of rows in the current page.
  uint32_t row_offset = row_num % ROWS_PER_PAGE;
  uint32_t byte_offset = row_offset * ROW_SIZE;
  return page + byte_offset;
}

void serialize_row(Row* source, void* destination){
  memcpy(destination + ID_OFFSET, &(source->id), ID_SIZE);
  memcpy(destination + USERNAME_OFFSET, &(source->username), USERNAME_SIZE);
  memcpy(destination + EMAIL_OFFSET, &(source->email), EMAIL_SIZE);
}

void deserialize_row(void* source, Row* destination){
  memcpy(&(destination->id), source + ID_OFFSET, ID_SIZE);
  memcpy(&(destination->username), source + USERNAME_OFFSET, USERNAME_SIZE);
  memcpy(&(destination->email), source + EMAIL_OFFSET, EMAIL_SIZE);
}

void print_row(Row* row){
  printf("(%d, %s, %s)\n",row->id, row->username, row->email);
}
