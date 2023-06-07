
function fillArray()
{
    let n1 = document.getElementById("1E").value;
    let n2 = document.getElementById("2E").value;
    let n3 = document.getElementById("3E").value;
    let n4 = document.getElementById("4E").value;
    let n5 = document.getElementById("5E").value;
    let n6 = document.getElementById("6E").value;
    let n7 = document.getElementById("7E").value;
    let n8 = document.getElementById("8E").value;
    let n9 = document.getElementById("9E").value;

    let arregloDesordenado = [n1,n2,n3,n4,n5,n6,n7,n8,n9];

    return arregloDesordenado;
}

function displayArray(arraySort)
{
    valor1 = document.getElementById("1S");
    valor2 = document.getElementById("2S");
    valor3 = document.getElementById("3S");
    valor4 = document.getElementById("4S");
    valor5 = document.getElementById("5S");
    valor6 = document.getElementById("6S");
    valor7 = document.getElementById("7S");
    valor8 = document.getElementById("8S");
    valor9 = document.getElementById("9S");
    valor1.value = arraySort[0];
    valor2.value = arraySort[1];
    valor3.value = arraySort[2];
    valor4.value = arraySort[3];
    valor5.value = arraySort[4];
    valor6.value = arraySort[5];
    valor7.value = arraySort[6];
    valor8.value = arraySort[7];
    valor9.value = arraySort[8];
}

function bubbleSort(reversa = false)
{
    let inputArr = fillArray();

    const len = inputArr.length;
    for (let i = 0; i < len; i++) {
        for (let j = i + 1; j < len; j++) {
            let a = inputArr[i];
            let b = inputArr[j];
            if (reversa ? a < b : a > b) {
                const tmp = inputArr[j];
                inputArr[j] = inputArr[i];
                inputArr[i] = tmp;
            }
        }
    }
    
    displayArray(inputArr);
    //document.write(inputArr);
    //return inputArr;
}

function mergeSortFinal(){
    let  inputArr = fillArray();
    inputArr = mergeSort(inputArr);
    displayArray(inputArr);
    
}

function merge(left, right) {
    let arr = []
    // Salir del bucle si alguno de los arreglos queda vacío
    while (left.length && right.length) {
        // Elegir el elemento menor entre los elementos más pequeños de
        // los subarreglos
        
        if (left[0] < right[0]) {
            arr.push(left.shift())  
        } else {
            arr.push(right.shift()) 
        }
    }
    
    // Concatenar los elementos sobrantes
    // (en caso de que no hayamos pasado por todo el arreglo, izquierdo o derecho)
    return [ ...arr, ...left, ...right ]
}


function mergeSort(array) {

    const half = array.length / 2
    
    // ¿Terminar?
    if(array.length < 2){
      return array 
    }
    
    const left = array.splice(0, half)
    return merge(mergeSort(left),mergeSort(array))
  }

  function partition(arr, start, end){
    // Tomando el último elemento como Pivote
    const pivotValue = arr[end];
    let pivotIndex = start; 
    for (let i = start; i < end; i++) {
        if (arr[i] < pivotValue) {
        // Intercambiando elementos
        [arr[i], arr[pivotIndex]] = [arr[pivotIndex], arr[i]];
        // Moviéndose al siguiente elemento
        pivotIndex++;
        }
    }
    
    // Poniendo enmedio el valor del Pivote
    [arr[pivotIndex], arr[end]] = [arr[end], arr[pivotIndex]] 
    return pivotIndex;
};
  

  
  function quickSortIterative()
{
    // Creando un arreglo que usaremos como una pila,
    // usando los métodos push() y pop()
    arr = fillArray();
    stack = [];
    
    // Agregando todo el arreglo inicial como un "subarreglo sin ordenar"
    stack.push(0);
    stack.push(arr.length - 1);
    
    // El bucle se repite mientras tengamos subarreglos sin ordenar
    while(stack[stack.length - 1] >= 0){
        
        // Extrayendo el subarreglo sin ordenar superior
        end = stack.pop();
        start = stack.pop();
        
        pivotIndex = partition(arr, start, end);
        
        // Si hay elementos sin ordenar a la izquierda del pivote,
        // Añadimos dicho subarreglo a la pila para que podamos ordenarlo luego
        if (pivotIndex - 1 > start){
            stack.push(start);
            stack.push(pivotIndex - 1);
        }
        
        // Si hay elementos sin ordenar a la derecha del pivote,
        // Añadimos dicho subarreglo a la pila para que podamos ordenarlo luego
        if (pivotIndex + 1 < end){
            stack.push(pivotIndex + 1);
            stack.push(end);
        }
    }
    //document.write(arr);
    displayArray(arr);
}

function quickSortFinal(){
    arr = fillArray();
    quickSortRecursive(arr,0,arr.length-1);
    displayArray(arr);
}

function quickSortRecursive(arr, start, end) {
    // ¿Ha llegado al fin?
    if (start >= end) {
        return;
    }
    
    // Devuelve el índice del Pivote
    let index = partition(arr, start, end);
    
    // Recursivamente aplica la misma lógica a los arreglos izquierdo y derecho
    quickSortRecursive(arr, start, index - 1);
    quickSortRecursive(arr, index + 1, end);
}