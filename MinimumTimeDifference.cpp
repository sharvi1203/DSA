/*
  Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
  Example 1:
  Input: ["23:59","00:00"]
  Output: 1
  Note:
  The number of time points in the given list is at least 2 and won't exceed 20000.
  The input time is legal and ranges from 00:00 to 23:59.
*/

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> minutes;
        for(int i=0;i<n;i++){
            int hour1=timePoints[i][0]-'0';
            //cout<<hour1<<endl;
            int hour2=timePoints[i][1]-'0';
            //cout<<hour2<<endl;
            int min1=timePoints[i][3]-'0';
            //cout<<min1<<endl;
            int min2=timePoints[i][4]-'0';
            //cout<<min2<<endl;
            minutes.push_back((hour1*10+hour2)*60+(min1*10+min2));
            //cout<<(hour1*10+hour2)*60+(min1*10+min2)<<endl;
        }
        sort(minutes.begin(),minutes.end());
        int Min=INT_MAX;
        for(int i=1;i<n;i++){
            Min=min(Min,minutes[i]-minutes[i-1]);
        }
        return min(Min,abs(minutes[0]+24*60 - minutes[n-1]));
    }
};
