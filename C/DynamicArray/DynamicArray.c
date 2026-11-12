#include <stdlib.h>
#include <stdio.h>

typedef struct DArray{
    int* arr;
    size_t capacity;
    size_t size;
} DArray;

DArray* initialize_array(){
    DArray* res = (DArray*)malloc(sizeof(DArray));
    if(res == NULL){
        fprintf(stderr, "Error : DArray initialization failed\n");
        exit(EXIT_FAILURE);
    }
    res->arr = (int*)malloc(sizeof(int) * 8);
    if(res->arr == NULL){
        fprintf(stderr, "Error : DArray (int*) component initialization failed\n");
        exit(EXIT_FAILURE);
    }
    res->capacity = 8;
    res->size = 0;
    
    return res;
}

void resize_array(DArray* darr){
    int* temp = (int*)malloc(sizeof(int) * darr->capacity * 2);
    if(temp == NULL){
        fprintf(stderr, "Error : Resizing array failed, new array couldn't be initialized\n");
        exit(EXIT_FAILURE);
    }
    darr->capacity *= 2;
    for(size_t i = 0; i < darr->size; i++){
        temp[i] = darr->arr[i];
    }
    free(darr->arr);
    darr->arr = temp;
}

int get_arr_val(DArray* darr, size_t k){
    if(k >= darr->size){
        printf("Error : index is outside of array\n");
        return -1;
    }
    return darr->arr[k];
}

int get_first_arr(DArray* darr){
    if(darr->size == 0){
        printf("Error : Array is empty\n");
        return -1;
    }else{
        return darr->arr[0];
    }
}

int get_last_arr(DArray* darr){
    if(darr->size == 0){
        printf("Error : Array is empty\n");
        return -1;
    }else{
        return darr->arr[darr->size - 1];
    }
}

void addlast_arr(DArray* darr, int val){
    if(darr->size == darr->capacity){
        resize_array(darr);
        darr->arr[darr->size++] = val;
    }else{
        darr->arr[darr->size++] = val;
    }
}

void pop_back_arr(DArray* darr){
    if(darr->size != 0){
        darr->size--;
    }
}

void set_at(DArray* darr, size_t k, int val){
    if(k > darr->size){
        printf("Error : index is outside of array\n");
    }else if(k == darr->size){
        addlast_arr(darr, val);
    }else{
        darr->arr[k] = val;
    }
}

size_t get_arr_capacity(DArray* darr){
    return darr->capacity;
}

size_t get_arr_size(DArray* darr){
    return darr->size;
}

int is_empty_arr(DArray* darr){
    return darr->size == 0;
}

void clear(DArray* darr){
    darr->size = 0;
}

int* get_data_arr(DArray* darr){
    return darr->arr;
}

void reserve(DArray* darr, size_t n){
    if(n < darr->size){
        printf("Warning : new size is smaller than previous array, values will be lost\n");
    }
    int* tmp = (int*)malloc(sizeof(int) * n);
    if(tmp == NULL){
        printf("Error : memory allocation of new array failed, operation aborted\n");
        return;
    }
    for(size_t i = 0; i < n; ++i){
        tmp[i] = darr->arr[i];
    }
    free(darr->arr);
    darr->capacity = n;
    darr->arr = tmp;
}

void shrink_to_fit_arr(DArray* darr){
    int* tmp = (int*)malloc(sizeof(int) * darr->size);
    if(tmp == NULL){
        printf("Error : memory allocation of new array failed, operation aborted\n");
        return;
    }
    for(size_t i = 0; i < darr->size; ++i){
        tmp[i] = darr->arr[i];
    }
    free(darr->arr);
    darr->capacity = darr->size;
    darr->arr = tmp;
}

void remove_at_arr(DArray* darr, size_t k){
    if(k > darr->size){
        printf("Error : index k=%d is out of array\n", k);
        return;
    }
    for(size_t i = k; i < darr->size-1; ++i){
        darr->arr[i] = darr->arr[i+1];
    }
    darr->size--;
}

void print_arr(DArray* darr){
    if(darr->size == 0){
        printf("{}");
        return;
    }
    printf("{");
    for(size_t i = 0; i < darr->size-1; ++i){
        printf("%d, ", darr->arr[i]);
    }
    printf("%d", darr->arr[darr->size-1]);
    printf("}\n");
}

void free_arr(DArray* darr){
    free(darr->arr);
    free(darr);
}

int main(void){
    DArray* test = initialize_array();
    addlast_arr(test, 1);
    addlast_arr(test, 2);
    addlast_arr(test, 3);
    set_at(test, 2, 100);
    addlast_arr(test, 4);
    addlast_arr(test, 5);
    remove_at_arr(test, 4);
    print_arr(test);
    free_arr(test);
    return 0;
}