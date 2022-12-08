#include <stdio.h>

// Guilherme Leite Félix
// Amadeu Mateus de Vasconcelos Neto

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// n é o tamanho do heap
// i é a raiz do array
void heapify (int arr[], int n, int i){
    int largest = i;

    // filho esquerdo
    int left = 2 * i + 1;

    // filho direito 
    int right = 2 * i + 2;

    // se o filho esquerdo for maior que a raiz
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // se o filho direito for maior que a raiz
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }


    // faz o swap e continua executando heapify se a raiz não for o maior
    if (largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// função que executa o heapsort
void heapSort(int arr[], int n){
    // cria o max-heap
    for (int i= n / 2 - 1; i >= 0; i --){
        heapify(arr, n, i);
    }

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // executa o heapify para o obter o maior número na raiz novamente
        heapify(arr, i, 0);
    }
}

// função para imprimir o array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 8, 3, 2, 6, 12, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);
    printf("Lista ordenada através do heapsort:\n");
    printArray(arr, n);
}