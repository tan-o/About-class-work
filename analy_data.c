#include<stdio.h>
#include <stdlib.h>

int main() {
    system("python get_data.py");

    FILE *fp1=NULL;
    FILE *fp2=NULL;
    char name[128]={""};
    double m=0,sum=0;
    int n=0,data[128]={0},i=0;
    char chart[100][128]={""};

    printf("***********************************\n");
    printf("*  ����Ŀ������Ѷ�ṩ����������api   *\n");
    printf("****������Դ��һ�����£������ο�******\n");
    printf("����ʡ������ȷ��������\n");

    fp1=fopen("data.d","r");
    fp2=fopen("data.n","r");

    while(!feof(fp1)) {
        fscanf(fp1,"%d",&data[n]);
        if(data[n]<0)
            data[n]=0;
        sum+=data[n];
        n++;
    }
    m=--n;
    while (i<n) {
        fscanf(fp2,"%s",name);
        printf("%d %s:%d ��\n",i,name,data[i]);
        i++;
    }
    // ��ͼ
    for (int i=0;i<n;i++) {
        m=(data[i]/sum)*100;
        if(data[i]==0)
            m=0;
        if(m<2&&m>1)
            m=1;
        for(int j=m;j>0;j--) {
            chart[j][i]='#';
        }
    }
    printf("�����ٷֱȣ�\n");
    for(int i=0;i<n;i++) {
        printf("%d",i);
        if(i!=n-1)
            printf("|");
    }
    for(int i=0;i<100;i++) {
        for(int j=0;j<n;j++)
            printf("%c ",chart[i][j]);
        printf("\n");
    }
    printf("ϣ�����������������ּ��ͣ��������ͣ�\n");
    system("pause");
}
