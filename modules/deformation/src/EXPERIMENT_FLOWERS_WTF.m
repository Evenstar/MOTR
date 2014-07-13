data=load('../../hmars/data/oxfordflower/flower160.mat');
data=data.CImages/255;
r=4;
N=20000;
trainImg=titan_build_train(data,r,N);
opts.patchSize=[r,r];
opts.numAtoms=r*r;
opts.lambda=5;
opts.maxIter=200;
[dict,recImg,ratio]=nenya_train(trainImg,opts);
psnr(trainImg,recImg)
ratio
resImg=trainImg-recImg;
L1=sum(abs(resImg(:)))
%%
dict=sortdict(dict);
seqx=[];
for i=1:160
    i
img=data(:,:,i);
st=wtfdec2(img,dict,5,3);
sequence=seq_wtf_l1(st);
seqx=[seqx;sequence];
end

%%
save('../data/flowers_wtf_l1','seqx','seqy');