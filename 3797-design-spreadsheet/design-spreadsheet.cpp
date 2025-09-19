class Spreadsheet {
public:
    unordered_map<string,int>cells;
    Spreadsheet(int rows){
    }
    
    void setCell(string cell, int value) {
        cells[cell]=value;
    }
    
    void resetCell(string cell) {
        cells.erase(cell);
    }
    
    int getValue(string formula) {
        int idx=formula.find('+');
        string left=formula.substr(1,idx-1);
        string right=formula.substr(idx+1);
        int vall=isalpha(left[0])?(cells.count(left)?cells[left]:0):stoi(left);
        int valr=isalpha(right[0])?(cells.count(right)?cells[right]:0):stoi(right);
        return vall+valr;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */