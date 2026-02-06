class Solution {
public:
    int lower_bound(vector<char>& letters, char target) {
        int left = 0, mid = 0;
        int right = letters.size() - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (letters[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int res = lower_bound(letters, target + 1);
        if (res >= letters.size())  //>= 说明没找到
            return letters[0];
        else
            return letters[res];
    }
};