/**
* ����������ӣ�
* ��ĿҪ�����ϵͳҪʹ�ó�������������long�ķ�Χ�����������һ�����ݽṹ���洢����
* �����������Լ����һ���㷨��ʵ�ֳ��������ļӷ�����
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
	* @param a �����ַ���1
	* @param b �����ַ���2
	* @return ����ַ���
	* ������
	* 1��ȡ�������ַ����ĳ���
	* 2���������ĳ������Ƚϣ����ó��ϳ��ĳ��ȣ����϶̵ĳ���
	* 3���ѳ��Ƚ϶̵ļ����ַ����������油0��ʹ֮��ϳ����ַ���һ����
	* 4�������λ��һ��������ȡ������ӣ���Ȼ���ȵ�ת��Ϊ����
	* 5�����ý�λ�������������Ӽ����Ͻ�λ���ڵ���10�������ⲻ�������һ���ַ���ӣ���ӽ������
	*    ��ȡ��1��ȡ��2����λ����10�����ѽ�λ��Ϊ1�����û�д���10���Ͱѽ�λ��Ϊ0����Щѭ������
	*    ��ӵĽ�����ַ�������ʽ����������͵õ����Ľ��
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
		//�ѳ��ȵ�������ͬ   
		if (maxLen == lenA)
		{
			b = strTmp + b;
		}
		else
			a = strTmp + a;
		int JW = 0;//��λ   
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