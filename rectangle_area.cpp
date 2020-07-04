class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a1=abs(A-C)*abs(B-D);
        int a2=abs(E-G)*abs(F-H);
        int left=max(A,E);
        int right=max(left,min(C,G));
        int bottom=max(B,F);
        int up=max(bottom,min(D,H));
        int a3=abs(left-right)*abs(bottom-up);
        return a1+(a2-a3);
    }
};
