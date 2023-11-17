# Matrix

<p align="center">
<img src=Images/code-purpose-of-life.gif>
</p>

## Условие задачи

На стандартный ввод приходит размер n и далее все элемент построчно. На стандартном выводе должно быть значение определителя.

В данной задаче я реализовал класс Матрицы и для квадратных реализовал посик её определителя при помощи [метода Гаусса](https://mipt.ru/online/#video.php?id=119855&search&chair=0&course=0&teacher=6493&semester=0&embedded=1&searchpage=0&videopage=0&playlistid=751).

Для установки проекта:

```
git clone git@github.com:Pelmeshka127/Matrix.git

cd Matrix
```

Для запуска проекта:

```
cmake -B build

cd build/src

cmake --build .

./matrix

```

Для unit тестирования

```
cmake -B build

cd build/tests/unit

cmake --build .

./unit
```

Для генерации простых ete тестов:

```
cd tests/ete

python3 simpletest.py
```

Для генерации больших ete тестов рекоммендуется:

```
cd tests/ete

python3 largematrix.py```

Для запуска ete тестов:

```
cmake -B build

cd build/tests/ete

cmake --build .

./ete <test_name>
```