# AVSP
[Analysis of Massive Data Sets](https://www.fer.unizg.hr/en/course/aomds)

## Project theme: Source code quality prediction 

Project is written in Python 3, using Jupyter Notebook. 
Goal of this project was to explore online tools for feature extraction from programmers source code.
Source code was reduced to .cpp code only, due to many reasons, mainly because its usage is widespread and easy to obtain online.
Dataset consisted of ~18k source codes obtained from Google-s [Code Jam](https://code.google.com/codejam/) competitions.
Online tools provided us, unfortunately, with only 34 different features.
After feature extraction, we wanted to analyze and see if we could find any linear correlation between features.
Finally, we implemented some basic classification models to see how good the results can get with a very small feature vector.

## Table of contents

<a href="#Req">Requirements</a><br>
<a href="#analyzers">Code Analyzers</a><br>
<a href='#Results'>Example results</a><br>

## Requirements
<a id='Req'></a>


```
Python 3
Jupyter Notebook
```

# Code Analyzers
<a id='analyzers'></a>

The follow online tools for feature extraction were used:

    1. [CodeAnalyzer](http://www.codeanalyzer.teel.ws/)
    
    2. [CCCC - C and C++ Code Counter](http://cccc.sourceforge.net/)
    
    3. [srcML](https://en.wikipedia.org/wiki/SrcML)
    
Features extracted were following:

```
0   number_of_modules
1   lines_of_code
2   lines_of_code_per_module
3   McCabes_cyclomatic_complexity
4   McCabes_cyclomatic_complexity_per_module
5   lines_of_comment
6   lines_of_comment_per_module
7   lines_of_code_per_line_of_comment
8   McCabes_cyclomatic_complexity_per_line_of_comment
9   IF4
10  IF4_per_module
11  IF4_visible
12  IF4_visible_per_module
13  IF4_concrete
14  IF4_concrete
15  rejected_lines_of_code

16  Files
17  Lines
18  AVG Len
19  Code
20  Comments
21  White SP
22  Cd/Cm+WS
23  Cd/Cm
24  Cd/WS
25  % Code
26  cnt_classes
27  max_member_funs
28  max_nested_loops
29  max_nesting_depth
30  max_params_in_decl
31  member_funs
32  member_vars
33  min_member_funs
```

## Results
<a id='Results'></a>
