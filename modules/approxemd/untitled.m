clc
clear 
load mnist_uint8
train_x=double(train_x);
data=train_x/255.0;
data=data(1:100,:);
data=reshape(data',[28,28,100]);
imshow(data(:,:,1),[])

%%
R= 28
C= 28
tic
THRESHOLD=3000;
D= zeros(R*C,R*C);
j= 0;
for c1=1:C
    for r1=1:R
        j= j+1;
        i= 0;
        for c2=1:C
            for r2=1:R
                i= i+1;
                D(i,j)= min( [THRESHOLD (abs(c1-c2)+abs(r1-r2))] );
            end
        end
    end
end
extra_mass_penalty=-1;
flowType= 3;
toc
%%
DIST=zeros(100,100);
for i=1:100
    i
    for j=1:100
im1=data(:,:,i);
im2=data(:,:,j);
P= im1(:);
Q= im2(:);
tic
DIST(i,j)= emd_hat_gd_metric_mex(P,Q,D,extra_mass_penalty);
    end
end
%%
ydata=train_y(1:100,:);
ylabel=zeros(100,1);
for i=1:100
    for j=1:10
        if ydata(i,j)~=0
           ylabel(i)=j;
        end
    end
end











