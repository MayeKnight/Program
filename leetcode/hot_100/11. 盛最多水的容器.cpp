//如果数组有序, 就可以使用双向双指针了
//见"https://www.bilibili.com/video/BV1bP411c7oJ?vd_source=d87bfce5f3f31ab12142d953a0599436&spm_id_from=333.788.videopod.sections"
//"https://www.bilibili.com/video/BV1Qg411q7ia?vd_source=d87bfce5f3f31ab12142d953a0599436&spm_id_from=333.788.player.switch"
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, h = 0, ans = 0;
        while (left < right) {
            h = min(height[left], height[right]);
            ans = max(h * (right - left), ans);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return ans;
    }
};