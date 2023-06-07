<?php
include 'ordenamientos.php';

$contenedor = '';

if (isset($_POST['bubble_sort'])) {
    $sorted_arr = bubble_sort(getNumbersFromInputs());

    $contenedor = generateBoxesFromNumbers($sorted_arr);
}

if (isset($_POST['merge_sort'])) {
    $numerosOrdenados = mergeSort(getNumbersFromInputs());

    $contenedor = generateBoxesFromNumbers($numerosOrdenados);
}

if (isset($_POST['quick_sort'])) {
    $ordenados = quickSortIterativo(getNumbersFromInputs());

    $contenedor = generateBoxesFromNumbers($ordenados);
}

if (isset($_POST['quick_sort_recursive'])) {
    $sorted = quick_sort_recursive(getNumbersFromInputs());

    $contenedor = generateBoxesFromNumbers($sorted);
}

function getNumbersFromInputs() {
    $numeros = [];

    for ($i = 1; $i <= 9; $i++) {
        $input_name = $i . 'E';

        if (isset($_POST[$input_name])) {
            $numeros[] = $_POST[$input_name];
        }
    }

    return $numeros;
}

function generateBoxesFromNumbers($numbers) {
    $contenedor = '';

    foreach ($numbers as $numero) {
        $contenedor .= "<div class='capa'>$numero</div>";
    }

    return $contenedor;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Ordenamientos</title>

    <link rel="stylesheet" href="styles.css">
</head>
<body>

    <h2>Algoritmos de ordenamiento</h2>

    <form method="POST">
        <label>Entrada:</label> <br>
        <input type="text" name="1E" size="12">
        <input type="text" name="2E" size="12">
        <input type="text" name="3E" size="12">
        <input type="text" name="4E" size="12">
        <input type="text" name="5E" size="12">
        <input type="text" name="6E" size="12">
        <input type="text" name="7E" size="12">
        <input type="text" name="8E" size="12">
        <input type="text" name="9E" size="12">

        <br><br>

        <button type="submit" name="bubble_sort">BubbleSort</button>
        <button type="submit" name="merge_sort">MergeSort</button>
        <button type="submit" name="quick_sort">Quick Sort Iterativo</button>
        <button type="submit" name="quick_sort_recursive">Quick Sort Recursivo</button>
    </form>

    <div id="contenedor"><?php echo $contenedor; ?></div>

</body>
</html>
