%demo_emd_appxoximation_1
clc
clear
load('../../data/mnist_uint8.mat');

r=6;
N=20000;
temp=reshape(train_x,[28,28,60000]);
trainImg=titan_build_train(temp,r,N);
opts.patchSize=[r,r];
opts.numAtoms=r*r;
opts.lambda=30;
opts.maxIter=200;
[dict,recImg,ratio]=nenya_train(trainImg,opts);
%%
n=20;
data=double(train_x(1:n,:))/255.0;
data=reshape(data',[28,28,n]);
load('../../data/DIST20.mat');
dist=sort(Dist(:));
dist2=zeros(n,n);
dist3=zeros(n,n);
for i=1:n
    i
    for j=1:n
        im=data(:,:,i)-data(:,:,j);
        dist2(i,j)=tfnorm_1(im,dict,3);
        dist3(i,j)=sum(abs(im(:)));
    end
end
dist2=sort(dist2(:));
dist3=sort(dist3(:));
%%
figure(1);plot(dist2,dist3,'o')
figure(2); plot(dist, dist2,'o')
figure(3);plot(dist,dist3,'o')