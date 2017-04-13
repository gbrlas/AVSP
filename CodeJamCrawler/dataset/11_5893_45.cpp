public class Test {

    public static void main(String[] args) {

//        Map<String,String> z  = new HashMap<String,String>();
//        z.put("a","1");
//        z.put("b","2");
//        z.put("c","3");
//
//        Iterator iter = z.keySet().iterator();
//
//        while(iter.hasNext()){
//            String value = (String) iter.next();
//            System.out.println("#"+ value +":"+z.get(value));
//        }

        StringBuffer s = new StringBuffer();
        s.append("ponnulingam");
        System.out.println(s.delete(0,s.length()));
    }
}
