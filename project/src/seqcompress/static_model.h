#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define REPEAT_TIMES 50
#define LENGTH_SUB_SEGMENT 8
char segment[1001]={0};

/* below are for testing only 
int main()

{	strcpy(segment,"ACATCAAGGACCTGCCTAAAGAAATCACTGTTGCTACATCACGAACGCTTTCTTATTACAAATTGGGAGCTTCGCAGCGTGTAGCAGGTGACTCAGGTTTTGCTGCATACAGTCGCTACAGGATTGGCAACTATAAATTAAACACAGACCATTCCAGTAGCAGTGACAATATTGCTTTGCTTGTACAGTAAGTGACAACAGATGTTTCATCTCGTTGACTTTCAGGTTACTATAGCAGAGATATTACTAATTATTATGAGGACTTTTAAAGTTTCCATTTGGAATCTTGATTACATCATAAACCTCATAATTAAAAATTTATCTAAGTCACTAACTGAGAATAAATATTCTCAATTAGATGAAGAGCAACCAATGGAGATTGATTAAACGAACATGAAAATTATTCTTTTCTTGGCACTGATAACACTCGCTACTTGTGAGCTTTATCACTACCAAGAGTGTGTTAGAGGTACAACAGTACTTTTAAAAGAACCTTGCTCTTCTGGAACATACGAGGGCAATTCACCATTTCATCCTCTAGCTGATAACAAATTTGCACTGACTTGCTTTAGCACTCAATTTGCTTTTGCTTGTCCTGACGGCGTAAAACACGTCTATCAGTTACGTGCCAGATCAGTTTCACCTAAACTGTTCATCAGACAAGAGGAAGTTCAAGAACTTTACTCTCCAATTTTTCTTATTGTTGCGGCAATAGTGTTTATAACACTTTGCTTCACACTCAAAAGAAAGACAGAATGATTGAACTTTCATTAATTGACTTCTATTTGTGCTTTTTAGCCTTTCTGCTATTCCTTGTTTTAATTATGCTTATTATCTTTTGGTTCTCACTTGAACTGCAAGATCATAATGAAACTTGTCACGCCTAAACGAACATGAAATTTCTTGTTTTCTTAGGAATCATCACAACTGTAGCTGCATTTCACCAAGAATGTAGTTTACAGTCATGTACTCAACATCAACCATATGTAGTTGATGACCC");
	//printf("%s",segment);
	flag = model_compress(segment);
}
*/

int model_compress(char *segment,FILE *des_file)
{
	int cycle_times = 0;
	char sub[5]={0};
	char temp_sub[5]={0};
	int i = 0;
	int j = 0;
	int count = 0;
	double ratio;

	for(i;i<992;i++)
	{
		int position[1000]={0};
		count = 0;
		cycle_times++;
		strncpy(sub,segment+sizeof(char)*i,4);
		for(j = i+1;j<992;j++)
		{	
			strncpy(temp_sub,segment+sizeof(char)*j,4);
			if(strcmp(sub,temp_sub)==0)
			{
				position[count++] = j;
				//printf("sub:%s is within temp_sub:%s\n",sub,temp_sub);
			}
		}
		//说明：ratio = 记录匹配次数+记录匹配项目长度/匹配次数*匹配项目长度
		ratio = ((count + 1 + 4)*1.0/((count + 1)*4))*100;
		//printf("i = %d,ratio = %f,count = %d\n",i,ratio,count+1);
		//printf("sub = %s,count = %d",sub,count);
		if(ratio<25) 
		{
		
			printf("hits = %d,sub = %s",count+1,sub);
			for(i=0;i<count;i++)
			{
				int integer=position[i];
				char str[10];
				sprintf(str,"%d",integer); 
				fputs(str,des_file);
			}
			return 1;
		}
		else
		{
			continue;
		}
		if(cycle_times>800) return 0;
		//0说明二进制压缩更加高效
	}
}

