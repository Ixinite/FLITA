#include <stdio.h>
#include <malloc.h>

int main() {
    int size1, size2, choice, n;

    printf("Введите размер 1-го множества:");
    scanf("%i",&size1);
    printf("Введите размер 2-го множества:");
    scanf("%i",&size2);
    int *array1;
    int *array2;
    array1 = (int*)malloc(size1 * sizeof(int));
    array2 = (int*)malloc(size2 * sizeof(int));
    
    for (int j = 0;j<size1;j++){
      printf("Введите %i-й элемент 1-го множества:", j+1);
      scanf("%i", &array1[j]);
    }
    for (int j = 0;j<size2;j++){
      printf("Введите %i-й элемент 2-го множества:", j+1);
      scanf("%i", &array2[j]);
    }

    while(1){
      printf("Выберите действие:\n1. Вывести элементы 1 множества\n2. Вывести элементы 2 множества\n3. Добавить элемент в 1 множество\n4. Добавить элемент во 2 множество\n5. Удалить элемент из 1-го множества\n6. Удалить элемент из 2-го множества\n0. Выйти из программы\nВведите номер команды:");
      scanf("%i",&choice);
      if(choice == 0){
        break;
      }
      else if(choice == 1){
          printf("Элементы 1-го множества:\n");
          for(int i = 0; i<size1; i++){
          printf("%d\n", array1[i]);
        }
      }
      else if(choice == 2){
          printf("Элементы 2-го множества:\n");
          for(int i = 0; i<size2; i++){
          printf("%d\n", array2[i]);
        }
      }
      else if(choice == 3){
        printf("Введите сколько добавить: ");
        scanf("%d", &n);
        array1 = (int*)realloc(array1, (size1 + n) * sizeof(int));
        
        for (int i = 0; i<n; i++)
        {
          printf("Введи %d-й эл-т:", i+1);
          scanf("%i", &array1[size1+i]);
        }
        size1 += n;
      }else if(choice == 4){
        printf("Введите сколько добавить: ");
        scanf("%d", &n);
        array2 = (int*)realloc(array2, (size2 + n) * sizeof(int));
        
        for (int i = 0; i<n; i++)
        {
          printf("Введи %d-й эл-т:", i+1);
          scanf("%i", &array2[size2+i]);
        }
        size2 += n;
      }else if(choice == 5){
          printf("Количество эл-ов: %d\nВведите № эл-та, который хотите удалить: ",size1);
          scanf("%i", &n);
          for(int i = (n - 1);i<(size1 - 1);i++){
              array1[i] = array1[i+1];
          }
          array1 = (int*)realloc(array1, (size1 - 1) * sizeof(int));
          size1--;
          
      }else if(choice == 6){
          printf("Количество эл-ов: %d\nВведите № эл-та, который хотите удалить: ",size2);
          scanf("%i", &n);
          for(int i = (n - 1);i<(size2 - 1);i++){
              array2[i] = array2[i+1];
          }
          array2 = (int*)realloc(array2, (size2 - 1) * sizeof(int));
          size2--;
      }
    }
  
    return 0;
}
