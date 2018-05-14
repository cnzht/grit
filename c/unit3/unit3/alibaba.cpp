/**
* 超大整数相加：
* 题目要求：如果系统要使用超大整数（超过long的范围），请你设计一个数据结构来存储这种
* 超大型数字以及设计一种算法来实现超大整数的加法运算
* @author Administrator
*
*/
public class VeryBigNumAdd {
	/**
	* @param args
	*/
	public static void main(String[] args) {
		// TODO Auto-generated method stub   
		/*
		String a="1223232";
		for(int i=a.length()-1;i>=0;i--)
		{
		System.out.print(a.charAt(i));
		}
		*/
		VeryBigNumAdd vbn = new VeryBigNumAdd();
		String a = "123453243455535634535252345234677576252241234123523453664563634";
		String b = "123453243455535634535252345234677576252241234123523453664563634";
		String result = vbn.doAdd(a, b);
		System.out.println("result:" + result);
	}
	/**
	*
	* @param a 加数字符串1
	* @param b 加数字符串2
	* @return 结果字符串
	* 分析：
	* 1、取得两个字符串的长度
	* 2、把两个的长度做比较，并得出较长的长度，及较短的长度
	* 3、把长度较短的加数字符串，在左面补0，使之与较长的字符串一样长
	* 4、从最高位，一个个数的取出来相加，当然首先得转换为整型
	* 5、设置进位，如果两个数相加及加上进位大于等于10，并且这不是最左边一个字符相加，相加结果等于
	*    （取出1＋取出2＋进位）－10，并把进位设为1；如果没有大于10，就把进位设为0，如些循环，把
	*    相加的结果以字符串的形式结合起来，就得到最后的结果
	*/
	String doAdd(String a, String b)
	{
		String str = "";
		int lenA = a.length();
		int lenB = b.length();
		int maxLen = (lenA>lenB) ? lenA : lenB;
		int minLen = (lenA<lenB) ? lenA : lenB;
		String strTmp = "";
		for (int i = maxLen - minLen; i>0; i--)
		{
			strTmp += "0";
		}
		//把长度调整到相同   
		if (maxLen == lenA)
		{
			b = strTmp + b;
		}
		else
			a = strTmp + a;
		int JW = 0;//进位   
		for (int i = maxLen - 1; i >= 0; i--)
		{
			int tempA = Integer.parseInt(String.valueOf(a.charAt(i)));
			int tempB = Integer.parseInt(String.valueOf(b.charAt(i)));
			int temp;
			if (tempA + tempB + JW >= 10 && i != 0)
			{
				temp = tempA + tempB + JW - 10;
				JW = 1;
			}
			else
			{
				temp = tempA + tempB + JW;
				JW = 0;
			}
			str = String.valueOf(temp) + str;
		}
		return str;
	}
}