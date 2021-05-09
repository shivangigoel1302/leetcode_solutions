if(n < 0){
            return false;
        }
        if(n == 0){
            return false;
        }
        double i = log10(n)/log10(3);
        if(i - (int)i == 0){
            return true;
        }
        return false;
