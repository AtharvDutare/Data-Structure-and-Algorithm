import java.util.*;

public class Main {
    private static int getSize(HashMap<String,HashSet<String>> tree,String head,HashMap<String,Integer> result) {
        if(!tree.containsKey(head)) {
            result.put(head,0);
            return 1;
        }
        int totalSize=0;
        for(String emp:tree.get(head)) {
            int temp=getSize(tree,emp,result);
            totalSize+=temp;
        }
        result.put(head,totalSize);
        return totalSize+1;
    }
    private static void getCount(HashMap<String,String> mp) {
        HashMap<String,HashSet<String>> tree=new HashMap<>();
        String ceo="";
        for(String emp:mp.keySet()) {
            String head=mp.get(emp);
            if(head.equals(emp)) {
                ceo=head;
            }
            if(tree.containsKey(head)) {
                    HashSet<String> empList=tree.get(head);
                    empList.add(emp);
                }
                else {
                    HashSet<String> empList=new HashSet<>();
                    empList.add(emp);
                    tree.put(head,empList);
                }
        }
        HashMap<String,Integer> result;
        int t=getSize(tree,ceo,result);

    }
}
