There is a O(n^3) time algorithms for solving the problem; i.e go throgh all the n^2 pairs of rows and for each pair (a,b) calculate the number of columns that contains a black square in both rows in O(n) time

-- Naive approach, picks 2 rows i & j then iterate all columns and check if all corneres are 1