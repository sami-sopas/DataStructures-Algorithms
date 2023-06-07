<?php

//BUBBLE SORT --------------------------------------------------
function bubble_sort($arr){
    $len = count($arr);
    for ($i = 0; $i < $len; $i++) {
        for ($j = 0; $j < $len - 1; $j++) {
            if ($arr[$j] > $arr[$j+1]) {
                $tmp = $arr[$j+1];
                $arr[$j+1] = $arr[$j];
                $arr[$j] = $tmp;
            }
        }
    }
    return $arr;
}

function mergeSort($arr) {
    $length = count($arr);
    
    if ($length <= 1) {
        return $arr;
    }
    
    $mid = (int) ($length / 2);
    $left = array_slice($arr, 0, $mid);
    $right = array_slice($arr, $mid);
    
    $left = mergeSort($left);
    $right = mergeSort($right);
    
    return merge($left, $right);
}

//MERGE SORT ---------------------------------------------------

function merge($left, $right) {
    $result = [];
    $i = 0;
    $j = 0;
    
    while ($i < count($left) && $j < count($right)) {
        if ($left[$i] <= $right[$j]) {
            $result[] = $left[$i];
            $i++;
        } else {
            $result[] = $right[$j];
            $j++;
        }
    }
    
    while ($i < count($left)) {
        $result[] = $left[$i];
        $i++;
    }
    
    while ($j < count($right)) {
        $result[] = $right[$j];
        $j++;
    }
    
    return $result;
}

//QUICK SORT ITERATIVO ---------------------------------------------
function quickSortIterativo($array)
{
    // Verificamos si el arreglo está vacío o tiene un solo elemento
    if (count($array) <= 1) {
        return $array;
    }

    // Inicializamos una pila
    $pila = array();
    $pila[] = 0;
    $pila[] = count($array) - 1;

    // Ciclo para realizar la ordenación iterativamente
    while (!empty($pila)) {
        $fin = array_pop($pila);
        $inicio = array_pop($pila);

        // Particionamos el arreglo
        $pivot = $array[($inicio + $fin) / 2];
        $i = $inicio - 1;
        $j = $fin + 1;

        while (true) {
            do {
                $i++;
            } while ($array[$i] < $pivot);

            do {
                $j--;
            } while ($array[$j] > $pivot);

            if ($i >= $j) {
                break;
            }

            // Intercambiamos los elementos
            $temp = $array[$i];
            $array[$i] = $array[$j];
            $array[$j] = $temp;
        }

        // Ordenamos las sub-listas de manera recursiva
        if ($inicio < $j) {
            $pila[] = $inicio;
            $pila[] = $j;
        }

        if ($j + 1 < $fin) {
            $pila[] = $j + 1;
            $pila[] = $fin;
        }
    }

    return $array;
}

//QUICK SORT RECURSIVO -------------------------------------------------
function quick_sort_recursive($arr)
{
    if (count($arr) <= 1) {
        return $arr;
    }

    $pivot = $arr[0];
    $left = [];
    $right = [];

    for ($i = 1; $i < count($arr); $i++) {
        if ($arr[$i] < $pivot) {
            $left[] = $arr[$i];
        } else {
            $right[] = $arr[$i];
        }
    }

    return array_merge(
        quick_sort_recursive($left),
        [$pivot],
        quick_sort_recursive($right)
    );
}



?>