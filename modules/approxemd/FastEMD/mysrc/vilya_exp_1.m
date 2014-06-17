load mnist_uint8
%%
data=double(train_x(59981:60000,:))/255;
data=permute(data,[1,3,2]);
nimg=20;
im1=reshape(data(1,:),[28,28]);
im2=reshape(data(2,:),[28,28]);
R= size(im1,1);
C= size(im1,2);
if (~(size(im2,1)==R&&size(im2,2)==C))
    error('Size of images should be the same');
end
THRESHOLD= 5;
D= zeros(R*C,R*C);
j= 0;
for c1=1:C
    for r1=1:R
        j= j+1;
        i= 0;
        for c2=1:C
            for r2=1:R
                i= i+1;
                D(i,j)= min( [THRESHOLD (sqrt((r1-r2)^2+(c1-c2)^2))] );
            end
        end
    end
end
extra_mass_penalty= -1;
flowType= 3;
Dist=zeros(nimg,nimg);
for i=1:nimg
    for j=1:nimg
        im1=reshape(data(i,:),[28,28]);
        im2=reshape(data(j,:),[28,28]);
        P= im1(:);
        Q= im2(:);
        tic
        Dist(i,j)=emd_hat_gd_metric_mex(P,Q,D,extra_mass_penalty);
        fprintf(1,'emd_hat_gd_metric_mex time in seconds: %f\n',toc);
    end
end