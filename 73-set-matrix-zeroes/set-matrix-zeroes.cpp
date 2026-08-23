class Solution
{
    public:
        void setZeroes(vector<vector < int>> &matrix)
        {

            int n = matrix.size();
            int m = matrix[0].size();

           	// Check whether first row contains a zero
            bool firstRowZero = false;
            for (int j = 0; j < m; j++)
            {
                if (matrix[0][j] == 0)
                {
                    firstRowZero = true;
                    break;
                }
            }

           	// Check whether first column contains a zero
            bool firstColZero = false;
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][0] == 0)
                {
                    firstColZero = true;
                    break;
                }
            }

           	// Use first row and first column as markers
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < m; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }

           	// Set rows to zero
            for (int i = 1; i < n; i++)
            {
                if (matrix[i][0] == 0)
                {
                    for (int j = 1; j < m; j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }

           	// Set columns to zero
            for (int j = 1; j < m; j++)
            {
                if (matrix[0][j] == 0)
                {
                    for (int i = 1; i < n; i++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }

           	// Finally handle first row
            if (firstRowZero)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[0][j] = 0;
                }
            }

           	// Finally handle first column
            if (firstColZero)
            {
                for (int i = 0; i < n; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
};