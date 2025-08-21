class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n = version1.size(), m = version2.size();
        
        while (i < n || j < m) {
            string decimal1 = "";
            string decimal2 = "";

            while (i < n && version1[i] != '.') {
                decimal1 += version1[i];
                i++;
            }
            i++;

            while (j < m && version2[j] != '.') {
                decimal2 += version2[j];
                j++;
            }
            j++;

            int num1 = decimal1.empty() ? 0 : stoi(decimal1);
            int num2 = decimal2.empty() ? 0 : stoi(decimal2);

            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
        }

        return 0;
    }
};