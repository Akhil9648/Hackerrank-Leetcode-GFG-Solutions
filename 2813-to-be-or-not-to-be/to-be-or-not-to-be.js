var expect = function(val1) {
    return{
        toBe : function(val2){
            if(val1 === val2){
                return true;
            }
            else
                throw new Error("Not Equal");
        },

        notToBe : function(val2){
            if(val1 !== val2){
                return true;
            }
            else
                throw new Error("Equal");
        }
    }
    
};

/**
how to check answer:
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */