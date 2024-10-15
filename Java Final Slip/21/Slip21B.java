import java.util.*;


class Slip21B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		Hashtable<String, String> cityCode = new Hashtable<>();
		cityCode.put("Nashik", "0004");
		cityCode.put("Pune", "0001");
		cityCode.put("Mumbai", "0000");
		cityCode.put("Thane", "0010");

		cityCode.forEach((city, code) -> {
			System.out.println("City : " + city + ", Code : " + code);
		});
	
		System.out.print("Enter City Name to find code : ");
		String c = sc.nextLine();

		if(cityCode.containsKey(c))
		{
			System.out.println("STD code for " + c + " is : " + cityCode.get(c));
		}
		else
		{
			System.out.println("City not found in hashtable");
		}
	}
}