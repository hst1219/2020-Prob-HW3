(100次實驗)
data1=load('C:\Users\User\source\repos\prob code3\prob code3\PDF_x_3.c.txt');
data2=load('C:\Users\User\source\repos\prob code3\prob code3\PDF_y_3.c.txt');
x1=data1(:,1);
y1=data2(:,1);
x=linspace(0,100);
plot(x1,y1,'r');
xlabel('X>50');
ylabel('PDF');
lengend('100次實驗');



(10000次實驗)
data3=load('C:\Users\User\source\repos\prob code3\prob code3\PDF2_x_3.c.txt');
data4=load('C:\Users\User\source\repos\prob code3\prob code3\PDF2_y_3.c.txt');
x2=data3(:,1);
y2=data4(:,1);
x=linspace(0,100);
plot(x2,y2,'b');
xlabel('X>50');
ylabel('PDF');
lengend('10000次實驗');



(100&10000次實驗)
data1=load('C:\Users\User\source\repos\prob code3\prob code3\PDF_x_3.c.txt');
data2=load('C:\Users\User\source\repos\prob code3\prob code3\PDF_y_3.c.txt');
data3=load('C:\Users\User\source\repos\prob code3\prob code3\PDF2_x_3.c.txt');
data4=load('C:\Users\User\source\repos\prob code3\prob code3\PDF2_y_3.c.txt');
x1=data1(:,1);
y1=data2(:,1);
x2=data3(:,1);
y2=data4(:,1);
x=linspace(0,100);
plot(x1,y1,'r--',x2,y2,'b');
xlabel('X>50');
ylabel('PDF');
lengend('100次實驗','10000次實驗');
