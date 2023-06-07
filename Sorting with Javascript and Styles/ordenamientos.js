// BURBUJA ---------------------------------------------------------------------------------------
function BubbleSort() {
    // Leer los valores de los campos de entrada
    var numeros = [
      parseInt(document.getElementById('1E').value),
      parseInt(document.getElementById('2E').value),
      parseInt(document.getElementById('3E').value),
      parseInt(document.getElementById('4E').value),
      parseInt(document.getElementById('5E').value),
      parseInt(document.getElementById('6E').value),
      parseInt(document.getElementById('7E').value),
      parseInt(document.getElementById('8E').value),
      parseInt(document.getElementById('9E').value)
    ];
  
    // Algoritmo de ordenamiento burbuja
    for (var i = 0; i < numeros.length - 1; i++) {
      for (var j = 0; j < numeros.length - i - 1; j++) {
        if (numeros[j] > numeros[j + 1]) {
          // Intercambiar valores
          var temp = numeros[j];
          numeros[j] = numeros[j + 1];
          numeros[j + 1] = temp;
        }
      }
    }
  
    // Crear las capass para mostrar los números ordenados
    var contenedor = document.getElementById('contenedor');
    contenedor.innerHTML = '';
    for (var i = 0; i < numeros.length; i++) {
      // Crear una nueva capa para cada número
      var capa = document.createElement('div');
      capa.classList.add('capa');
      capa.textContent = numeros[i];
      contenedor.appendChild(capa);
    }
  }

// MERGE SORT-----------------------------------------------------------------------------------
function MergeSort() {
  // Obtener los números ingresados en los campos de texto
  const numeros = [];
  for (let i = 1; i <= 9; i++) {
    const campo = document.getElementById(i + "E");
    const valor = parseInt(campo.value);
    if (!isNaN(valor)) {
      numeros.push(valor);
    }
  }

  // Ordenar los números usando Merge Sort
  const numerosOrdenados = mergeSort(numeros);

  // Mostrar los números ordenados en el contenedor
  const contenedor = document.getElementById("contenedor");
  contenedor.innerHTML = "";
  numerosOrdenados.forEach(numero => {
    const capa = document.createElement("div");
    capa.className = "capa";
    capa.innerText = numero;
    contenedor.appendChild(capa);
  });
}

function mergeSort(numeros) {
  if (numeros.length <= 1) {
    return numeros;
  }

  const mitad = Math.floor(numeros.length / 2);
  const izquierda = numeros.slice(0, mitad);
  const derecha = numeros.slice(mitad);

  return merge(mergeSort(izquierda), mergeSort(derecha));
}

function merge(izquierda, derecha) {
  const resultado = [];
  let i = 0;
  let j = 0;

  while (i < izquierda.length && j < derecha.length) {
    if (izquierda[i] < derecha[j]) {
      resultado.push(izquierda[i]);
      i++;
    } else {
      resultado.push(derecha[j]);
      j++;
    }
  }

  return resultado.concat(izquierda.slice(i)).concat(derecha.slice(j));
}

// QUICK ITERATIVO ---------------------------------------------------------------------------------------

function QuickSortIterativo() {
  // Obtener los números ingresados en los campos de texto
  const numeros = [];
  for (let i = 1; i <= 9; i++) {
    const campo = document.getElementById(i + "E");
    const valor = parseInt(campo.value);
    if (!isNaN(valor)) {
      numeros.push(valor);
    }
  }

  // Ordenar los números usando Quick Sort Iterativo
  const numerosOrdenados = quickSortIterativo(numeros);

  // Mostrar los números ordenados en el contenedor
  const contenedor = document.getElementById("contenedor");
  contenedor.innerHTML = "";
  numerosOrdenados.forEach(numero => {
    const capa = document.createElement("div");
    capa.className = "capa";
    capa.innerText = numero;
    contenedor.appendChild(capa);
  });
}

function quickSortIterativo(numeros) {
  if (numeros.length <= 1) {
    return numeros;
  }

  const stack = [];
  stack.push(0);
  stack.push(numeros.length - 1);

  while (stack.length > 0) {
    const high = stack.pop();
    const low = stack.pop();

    const pivotIndex = partition(numeros, low, high);

    if (pivotIndex - 1 > low) {
      stack.push(low);
      stack.push(pivotIndex - 1);
    }

    if (pivotIndex + 1 < high) {
      stack.push(pivotIndex + 1);
      stack.push(high);
    }
  }

  return numeros;
}

function partition(numeros, low, high) {
  const pivot = numeros[high];
  let i = low - 1;

  for (let j = low; j < high; j++) {
    if (numeros[j] <= pivot) {
      i++;

      const temp = numeros[i];
      numeros[i] = numeros[j];
      numeros[j] = temp;
    }
  }

  const temp = numeros[i + 1];
  numeros[i + 1] = numeros[high];
  numeros[high] = temp;

  return i + 1;
}

// QUICK RECURSIVO ---------------------------------------------------------------------------------------

function QuickSortRecursivo() {
  // Obtener los números ingresados en los campos de texto
  const numeros = [];
  for (let i = 1; i <= 9; i++) {
    const campo = document.getElementById(i + "E");
    const valor = parseInt(campo.value);
    if (!isNaN(valor)) {
      numeros.push(valor);
    }
  }

  // Ordenar los números usando Quick Sort Recursivo
  quickSortRecursivo(numeros, 0, numeros.length - 1);

  // Mostrar los números ordenados en el contenedor
  const contenedor = document.getElementById("contenedor");
  contenedor.innerHTML = "";
  numeros.forEach(numero => {
    const capa = document.createElement("div");
    capa.className = "capa";
    capa.innerText = numero;
    contenedor.appendChild(capa);
  });
}

function quickSortRecursivo(numeros, izquierda, derecha) {
  if (izquierda < derecha) {
    const indicePivote = particionar(numeros, izquierda, derecha);
    quickSortRecursivo(numeros, izquierda, indicePivote - 1);
    quickSortRecursivo(numeros, indicePivote + 1, derecha);
  }
}

function particionar(numeros, izquierda, derecha) {
  const pivote = numeros[derecha];
  let i = izquierda - 1;

  for (let j = izquierda; j < derecha; j++) {
    if (numeros[j] < pivote) {
      i++;
      swap(numeros, i, j);
    }
  }

  swap(numeros, i + 1, derecha);
  return i + 1;
}

function swap(numeros, i, j) {
  const temp = numeros[i];
  numeros[i] = numeros[j];
  numeros[j] = temp;
}
