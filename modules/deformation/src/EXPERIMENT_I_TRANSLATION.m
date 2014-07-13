clc
img=double(rgb2gray(imread('emma.jpg')))/255;
shift=5;
patch0=img(1:end-shift,:,:);
patch1=img(shift+1:end,:,:);
subplot(1,2,1);
imshow(patch0);
subplot(1,2,2);
imshow(patch1);

norm(patch0(:)-patch1(:),'fro')

%%
scale=16;
low_patch_0=imresize(imresize(patch0,1/scale),1);
low_patch_1=imresize(imresize(patch1,1/scale),1);
subplot(1,2,1);
imshow(low_patch_0);
subplot(1,2,2);
imshow(low_patch_1);
norm(low_patch_0(:)-low_patch_1(:),'fro')

%%
[C0 S0]=wavedec2(patch0,6,'db4');
[C1 S1]=wavedec2(patch1,6,'db4');
seq0=integral_l1(C0,S0);
seq1=integral_l1(C1,S1);
diff=seq0-seq1;
%%
N=7000;
load mnist_uint8
train_x=double(train_x(1:N,:))/255;

seqx=[];
for i=1:N
    [C S]=wavedec2(reshape(train_x(i,:),[28,28]),4,'db4');
    seq=integral_l1(C,S);
    seqx=[seqx;seq];
end

seqy=zeros(N,1);
for i=1:N
    seqy(i)=find(train_y(i,:)~=0);
end
save('crudeseq','seqx','seqy');