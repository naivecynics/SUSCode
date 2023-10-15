# Report for the First Project of Database

### CS213 12213009 Langchu HUANG 黄朗初

---

## 0. Catalogue

- [1. Project Structure](#1-project-structure)
  
- [2. Implemented Function](#2-implemented-function)

- [3. Time Comparison](#3-time-comparison)

- [4. Conclusion](#4-conclusion)

- [5. Evaluation](#5-evaluation)

- [6. Appendix](#6-appendix)

---

## 1. Project Structure

The project contains following java class:

    Main.java                   // entrance and UI
    timeCalculator.java         // runtime calculator
    Film.java                   // single film file
    FileManipulation.java       // csv loader and file manipulation
    DatabaseManipulation.java   // sql connection and database manipulation

Other file:

    filmData.csv           // film data
    film_database.sql      // create table and load data
    report.md              // my report

## 2. Implemented Function

In both java and sql, the following functions are implemented:

    - Search
      - searchFilmByKeyword (String, String) // every column
      - searchFilmByNo (int) // binary optimization
    - Update
      - updateFilmByNo (int, String, String)
      - toTOttoo (String to) // set all director name "to" to "ttoo"
    - Delete
      - deleteFilmByNo (int)
    - Insert
      - insertFilm (String)

## 3. Time Comparison

The following table shows the execute time comparison between java and sql:

| Function | SQL| Java  | Function | SQL | Java  |
| :------------: | :----: | :---: | :------------: | :----: | :---: |
|  Initialization  |  213  |  1365  | toTOttoo (multiple update) |  168  |  15  |
|  Long String Search  |  12   |  13  |  Short String Search  |  18   |  66  |
|  Single Integer Search  |  2   |  6  |  Single Integer Search (Binary Optimization)  |  2   |  1  |
|  Multiple Integer Search  |  3   |  15  | Multiple Integer Search (Binary Optimization)  |  75   |  115  |
|  Update  |  2   |  2  |  Delete  |  2   |  3  |
|  Insert  |  4   |  1  |  Word Search  |  374   |  435  |

[1] unit: millisecond (ms).
[2] The time is calculated by the average of 10 times of execution.
[3] The sample input is shown in the last appendix section.

---

### Observe the table above can obtain that

1. The time of initialization of database is much less than that of file.
2. The time of sql is much less than that of java in most cases.
3. However, for some cases, the time of file is the same as that of sql, or even less than that of sql. These cases involve the update or insert of data, I guess that's because these manipulations contains the rearrangement of data structure in sql, which is not necessary in file manipulation.

## 4. Conclusion

1. The database management system can manage data conveniently and improve the efficiency of data retrieval greatly with less amount of code.
2. The reason of the high efficiency of database is that it maintains data structure that satisfies specific search algorithm, which can implement advanced search algorithm on these data structure (like B-tree).
3. Database promote a disciplined approach to data management, and analyze data in a variety of ways without huge amount of code to implement the algorithm.

## 5. Evaluation

### Advantages

- Implement the basic manipulation of database, including search, update, delete and insert.
- The data loader refers to the provided good loader, minimizing the time of data loading and execution.
- Compare the execute time of different functions, algorithm and implements, which can show the advantage and ground logic of database.

### Disadvantages

- The scale of data is not large enough to show the advantage of database.
- Time calculation contains the time of output, disabling the comparison of time consumption of different functions.
- The time of sql includes both execute time and fetch time, which is not accurate enough.

## 6. Appendix

### Data Source

The films data csv file (7.64MB) is download from

    http://www.idatascience.cn/dataset-detail?table_id=102802

which contains **10020 rows of films data**, including

    No,Title,Description,Director,Genre,Language,Year,Cast

### Test Sample Input

#### 1. Short String Search

    // search cast "Brad Pitt"
    database / file
    search
    cast
    Brad Pitt

#### 2. Long String Search

    // search description
    database / file
    search
    description
    Returning home from a shopping trip to a nearby town, bored suburban housewife Laura Jesson

#### 3. Word Search

    // search language "English"
    database / file
    search
    language
    English

#### 4. Integer Search

    // search film no 8659
    database / file
    search
    no
    8659

#### 5. Multiple Integer Search

    // search film year 1994
    database / file
    search
    year
    1994

#### 6. Update

    // update film no 10020 title "apple"
    database / file
    update
    10020
    title
    apple

#### 7. Delete

    // delete film no 10019
    database / file
    delete
    10019

#### 8. Insert

    database / file
    insert
    10050;breathless;french new wave;godard;cool;french;1946;a,b,c

#### 9. binary

    // search film no % 10 == 2
    database / file
    binary
    2

#### 10. toTOttoo

    // set all director name "to" to "ttoo"
    database / file
    toTOttoo
    ab
