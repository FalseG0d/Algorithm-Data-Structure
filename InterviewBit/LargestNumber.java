public class Solution {
    // DO NOT MODIFY THE LIST. IT IS READ ONLY
    public class SortNumbers implements Comparator<String>{
        @Override
        public int compare(String i1, String i2){
            return (i2+i1).compareTo(i1+i2);
        }
    }
    public String largestNumber(final List<Integer> A) {
        ArrayList<String>stringList=new ArrayList<String>();
        for(Integer i:A) stringList.add(Integer.toString(i));
        
        Collections.sort(stringList, new SortNumbers());
        String res="";

        for(String s:stringList){
            res+=s;
        }

        while(res.length()>0 && res.charAt(0)=='0'){
            res=res.substring(1);
        }

        return res.length()==0?"0":res;
    }
}