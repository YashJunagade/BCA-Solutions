class Slip2A{
  public static void main(String [] args){
    String str = "ImYashJunagade";

    String inputStr = str.toLowerCase();

    for(int i = 0; i < inputStr.length(); i++){
      char ch = inputStr.charAt(i);

      if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        System.out.print(ch + " ");
      }
    }
  }
}