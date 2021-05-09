#define ll long long int
class MKAverage {
    ll m,k,tot,midsum;
    queue<ll> dq;
    multiset<ll> low,mid,high;
public:
    MKAverage(int M, int K) {
        low.clear(); // store k smallest numbers in latest stream of m numbers
        high.clear();// stores k largest numbers in latest stream of m numbers
        mid.clear(); // stores the remaining numbers of the curr stream of numbers
        midsum=0; // sum of elements in middle midset
        m=M;
        tot=0; // intialized tot number of elements
        k=K;
    }

    void addElement(int num) {
		// push the current element into queue
        dq.push(num);
		// if number of elements < k then insert into smaller set only
        if(low.size()<k)
            low.insert(num);

        else{
			// initiallly we only fill low and high multisets
            if(high.size()<k){
                auto it=low.end();
                --it;
                // if given element is greater than current max of all k smallest
                if(*it<=num)
                    high.insert(num); // insert into high multiset
                else{
					// else insert new element into low and max from low into high multiset
                    int val=*it;
                    low.erase(it);
                    high.insert(val);
                    low.insert(num);
                }
            }
            // if tot >= 2*k
			// now we need to insert elements into middle set depending upon the following conditions
            else{
                auto it=low.end();
                --it;
                auto it2=high.begin();
				// if current number is one of the smallest then insert into low
				// insert the max of low into middle set
                if(num<*it){
                    ll val=*it;
                    low.erase(it);
                    mid.insert(val);
                    midsum+=val;
                    low.insert(num);
                }

				// if curr number is one of the k largest put into high
				// put the smallest from high into middle set
                else if(num>*it2){
                    ll val=*it2;
                    high.erase(it2);
                    mid.insert(val);
                    midsum+=val;
                    high.insert(num);
                }

				// if curr number itself lies in middle set inherently
                else{
                    mid.insert(num);
                    midsum+=num;
                }

				// if we have more than m elements we need to remove the oldest element from front of queue
				// we search for that element in three sets and do the needful maintainigng the size of low and high always equal to k
                if(dq.size()==m+1){
                    ll f=dq.front();
                    dq.pop();
					// if element in middle then delete from middle set and just be done with it
                    if(mid.find(f)!=mid.end()){
                        mid.erase(mid.find(f));
                        midsum-=f;
                    }
					// deletion from low decreases its size so need to insert one of the smaller element from middle set
                    else if(low.find(f)!=low.end()){
                        low.erase(low.find(f));
                        auto it=mid.begin();
                        ll val=*it;
                        midsum-=val;
                        mid.erase(it);
                        low.insert(val);
                    }
					// deletion from high reduces its size so we insert the max from middle into high set
                    else{
                        high.erase(high.find(f));
                        auto it=mid.end();
                        --it;
                        ll val=*it;
                        mid.erase(it);
                        midsum-=val;
                        high.insert(val);
                    }
                }
            }
        }
    }

    int calculateMKAverage() {
        ll ls=low.size(),ms=mid.size(),hs=high.size();
        tot=ls+ms+hs;
		// if tot size < m
        if(tot<m)
            return -1;
		// calculating the average
        ll mss=mid.size();
        ll ans=(midsum)/mss;
        return ans;
    }
};
