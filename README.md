# AVL Tree

[![CMake](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml/badge.svg)](https://github.com/Algorithms-and-Data-Structures-2021/semester-work-template/actions/workflows/cmake.yml)

-_АВЛ-дерево — это прежде всего двоичное дерево
поиска, ключи которого удовлетворяют стандартному
свойству: ключ любого узла дерева не меньше
любого ключа в левом поддереве данного узла и не
больше любого ключа в правом поддереве этого узла.
Это значит, что для поиска нужного ключа в АВЛдереве можно использовать стандартный алгоритм.
Для простоты дальнейшего изложения будем считать,
что все ключи в дереве целочисленны и не
повторяются_
- _Используется в ассоциативных массивахю Ассоциативный массив — абстрактная структура данных, для которой основными операциями являются "найти запись по ключу", "проверить наличие ключа в массиве", "добавить пару ключ-значение", "удалить запись". Во многих языках программирования, где структура включена в стандартную библиотеку, реализация сделана с помощью двоичных деревьев или хэш-таблиц. Языки семейства Лисп поддерживают ассоциативные списки. В конце концов, записи можно даже просто хранить в массиве в отсортированном порядке._
- _Доступные операции: балансировка узлов, вставка ключей, поиск ключа, удаление ключей_
- _Для AVL-дерева не существует наихудшего случая, так как оно является почти полным бинарным деревом. Сложность операции поиска составляет O(log2n)._
- _Опыт показывает, что повороты требуются примерно в половине случаев вставок и удалений. Сложность балансировки обусловливает применение AVL-деревьев только там, где поиск является доминирующей операцией._

## Команда Lost in space (1)

| Фамилия Имя   | Вклад (%) | Прозвище              |
| :---          |   ---:    |  ---:                 |
| Александр     | 60        |  кодер, властелин репозитория                |
| Фархат        | 20        |   документатор, теоретик        |
| Владимир      | 20        |  построитель отчётов, диаграмм, видеоператор  |

**Девиз команды**
> _Наши цели ясны. Задачи определены. За работу, товарищи!_

## Структура проекта

- [`src`](src)/[`include`](include) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска);
- [`dataset`](dataset) - наборы данных для запуска контрольных тестов и их генерация;

## Требования (Prerequisites)

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 3 ГБ (набор данных для контрольных тестов).

## Сборка и запуск

### Windows

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности IDE):

```shell
git clone https://github.com/Luwgod/semester-work-avl-tree.git
```

Для ручной сборки проекта в терминале введите:

```shell
# переход в папку с проектом
cd C:\Users\username\asd-projects\semester-work-avl-tree

# создание папки для файлов сборки (чтобы не засорять папку с проектом) 
mkdir -p build && cd build 

# сборка проекта
cmake .. -DCMAKE_BUILD_TYPE=RelWithDebInfo && cmake --config RelWithDebInfo --build . 
```

#### Генерация тестовых данных

Генерация тестового набора данных в
формате [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values):

```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_dataset.py
```
Скрипт достаточно запустить один раз. 
Будет сгенерировано 10 наборов(папок) данных с 10 файлами разного размера(количества данных) в каждой.
Генерируемые данные сохраняются в директории dataset/data


Тестовые данные представлены в CSV формате (см.
[`dataset/data/100.csv`](dataset/data/100.csv)):

```csv
78
11
35
...
```

**Примечание**. Тестовые данные хранятся в директориях:

```shell
dataset/data/
  01/
    100.csv
    ...
    5000000.csv
  02/ ...
  03/ ...
  ...
  10/ ...
  ...
```

По названию директории `/dataset/data/add` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.csv`. `5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов). 

#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `search_benchmark`        | поиск элементов по случайному индексу   | _время_         |
| `insert_benchmark`        | добавление элементов в структуру данных | _время_         |
| `delete_benchmark`        | удаление дерева в случайном порядке ключей    | _время_             |

##### Примеры запуска

```shell
./benchmark
```

Добавление случайных элементов в структуру данных
Операция повторяется 10 раз для выбранного набора данных. 

Результатом будет количество наносекунд за которое производится операция добавления, отдельно для каждого размера данных (100, 500, 1000...)
Таких результатов будет 10 за выполнение программы 

```
./insert_benchmark.exe
``` 
Результаты будут выведены в консоли (окне исполняемой программы)

## Источники

-https://habr.com/ru/post/123951/
-https://ru.wikipedia.org/wiki/АВЛдерево#Оценка_эффект
-https://habr.com/ru/post/150732/
-https://kvodo.ru/avl-tree.html
-https://cyberleninka.ru/article/n/avl-derevyavypolnen
-https://www.youtube.com/watch?app=desktop&v=4qJVF

