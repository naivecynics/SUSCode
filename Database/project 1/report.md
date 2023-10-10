# 要求解读

项目1:DBMS性能评估

数据库管理系统可以方便地管理数据，提高数据检索的效率很大。请将自己使用Java实现的数据检索和其他操作进行比较。用C/ c++或任何其他语言来查找DBMS的差异。

需求

． 找一些实验数据。你可以使用所有带有标题、导演、演员等的电影相关信息。其他一些数据，如“股票数据”，“图书馆数据”等也很好。但尺寸应该相当大。将数据存储到一个PostgreSQL数据库表中，并放入文件(您喜欢的任何格式)。

． 检索比较:在SQL中使用select查找标题中有“XXX”字样的电影并记录执行时间。执行完成后，可以从客户端获取执行时间。写一个Java或C/ c++程序通过文件来完成。比较两者的差异方法。

． 更新比较:在SQL中使用Update将人名中的“to”改为“TTOO”。写一个Java或C/ c++程序在文件中执行此操作。比较两种方法的差异。

． 你还想做一些其他的比较和实验。比如你可以重新组织将数据转换成其他格式以便更快地检索。建议您研究其机理DMBS的存储和检索。

报告

． 这是个人项目。每个学生应单独完成，并提交一份报告项目。

． 提交的报告应包含的设计，实施和评估函数。

． 介绍项目的主要特点和成果。

规则:

． 项目报告和源代码必须在截止日期前提交。任何在截止日期后提交(即使迟了1秒)，成绩为0分。截止日期是10月15日2359。

． 文件应以report.pdf、[filename]. java或[filename].cpp格式提交。这些文件应该不要被压缩成一个。

． 分数将取决于源代码和报告的质量。报告应该要易于理解，并提供一个清晰的项目描述，特别是重点。

# Report for the First Project of Database CS

## a comparsion of 

### 1. Data preparation

The films data csv file (7.64MB) is download from http://www.idatascience.cn/dataset-detail?table_id=102802 which contains **10020 rows of films data**, including **No,Title,Description,Director,Genre,Language,Year,Cast**.

### 2.Initialization

java:

1309 1118 3199 970 954 954 1034 1125 966 971 1047

sql:

