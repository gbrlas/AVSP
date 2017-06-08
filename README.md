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
<a href='#improvements'>Further improvements</a><br>

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
    
After extraction, it proved troublesome to parse features from different tools into python readable data.
In the repository, there are few scripts that help with that problem - should you feel the desire to try and test the dataset by yourself.

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

As we explained before, tools extracted 34 features.
We wanted to see how correlated the features could be. The results, along with visualization, can be found in <b>StatisticalAnalysis.ipynb</b> notebook.
The results of this linear uncorrelation proved to be beneficial only because we could be sure that we could use all of features for building our
model for code quality classification (feature vector is already small as is, it would be a shame to have to reduce it even further than 34).

So, given our dataset of ~18k feature vectors, and given the fact that we were able to provide results of each author in Code Jam competition, we had
all the data we need to build a supervised model for classification. The current ratings we decided for are 1-5 grades, corresponding to programmers results
in competitions (0-100) points.

Another problem we came upon is the fact that many programmers competed on a few competitions - meaning we would have 5,10 or even 15 source codes from the same author.
This turned out the be a problem because models could possibly learn to recognize authors code, which would prove too easy for them to recognize while testing.
Before building any models, we had to split the dataset feature vectors by authors. 80% of authors went to training set, while remaining was kept for testing.
We tried building simple models to see what results could be achieved with just a lazy model import, fit and predict aproach.
Results can be found inside <b>MachineLearningModels.ipynb</b> notebook.

If the model would return bellow 50%, we would instantly ignore it.

Should we get more than 50%, we would try optimizing hyperparameters, to see how can we could go with it.
Best results were obtained with following models:

```
[Decision Tree Classifier](http://scikit-learn.org/stable/modules/generated/sklearn.tree.DecisionTreeClassifier.html)

[Extra Tree Classifier](http://scikit-learn.org/stable/modules/generated/sklearn.tree.ExtraTreeClassifier.html) which is just a more general version of [Random Forest Classifier](https://en.wikipedia.org/wiki/Random_forest)
```
## Further improvements
<a id='improvements'></a>

    1.  Given the fact that we had only 34 features, the first logical thing would be to somehow obtain more features. We deduced that with 
        ~80-100 features we could possibly get to 85%+ accuracy score with our model.
        
    2.  Search for better models for classification
    
    3.  Play around with labels, try different rating systems
    
    4.  Try regression aswell, the dataset is more oriented to regression due to the domain of features, which makes classification a harder problem for this dataset.
    
    5.  Try and find some nonlinear correlations within features.