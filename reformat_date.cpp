class Solution {
public:
    string reformatDate(string date) {
        vector<string>months={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        int i = 0 ;
        int first = 0;
        while(i < date.size()){
            if(date[i] >= '0' && date[i] <= '9'){
                first = first*10 + date[i]-'0';
            }
            else{
                break;
            }
            i++;
        }
        i = 0;
       string month="";
            while(date[i] != ' '){
                i++;
            }
            int j = i+1;
             month = "";
            while(date[j] != ' '){
                month+=date[j];
                j++;
            }
            j++;
            int year = 0;
            while(j<date.size()){
                year= year*10 + date[j]-'0';
                j++;
            }

        int m = 0;
        for(int k = 0 ; k < 12 ; k++){
            if(months[k] == month){
                m = k+1;
                break;
            }
        }
        string final = to_string(year) + "-" ;
        if(m<=9){
            month ="0" + to_string(m);
        }
        else{
            month = to_string(m);
        }
        final+=month+"-";
        string start = "";
        if(first <= 9){
            start += "0" + to_string(first);
        }
        else{
            start = to_string(first);
        }
        final += start;

                                  return final;
    }
};
