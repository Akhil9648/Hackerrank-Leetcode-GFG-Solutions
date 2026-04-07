class Robot {
public:
    int n,m;
    int a=0,b=0;
    Robot(int width, int height) {
        n=height;
        m=width;
    }
    string dir="East";
    void step(int num) {
        int perimeter = 2 * (n + m) - 4;
        num %= perimeter;
        if(num == 0){
        if(a == 0 && b == 0){
            dir = "South";
        }
        return;
    }
        while(num>0){
            if(dir=="East"){
            int steps=(m-1)-b;
            if(num<=steps){
                b+=num;
                num=0;
            }
            else{
                b=m-1;
                num-=steps;
                dir="North";
            }
        }
        else if(dir=="West"){
            if(num<=b){
                b-=num;
                num=0;
            }
            else{
                num-=b;
                b=0;
                dir="South";
            }
        }
        else if(dir=="North"){
            int steps = (n - 1) - a;
            if(num<=steps){
                a+=num;
                num=0;
            }
            else{
                a=n-1;
                num-=steps;
                dir="West";
            }
        }
        else if(dir=="South"){
            if(num<=a){
                a-=num;
                num=0;
            }
            else{
                num-=a;
                a=0;
                dir="East";
            }
        }
        }
    }
    
    vector<int> getPos() {
        return {b,a};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */