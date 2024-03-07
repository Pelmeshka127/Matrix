# Matrix

<p align="center">
<img src=Images/code-purpose-of-life.gif>
</p>

## Условие задачи

В данной задаче я реализовал класс Матрицы и для квадратных реализовал поиск её определителя при помощи [метода Гаусса](https://ru.wikipedia.org/wiki/Метод_Гаусса_—_Жордана).

На стандартный ввод приходит размер n и далее все элемент построчно. На стандартном выводе должно быть значение определителя.

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

Для генерации больших ete тестов рекомендуется:

```
cd tests/ete

python3 largematrix.py
```

Для запуска ete тестов:

```
cmake -B build

cd build/tests/ete

cmake --build .

./ete <test_name>
```