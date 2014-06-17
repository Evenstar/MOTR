compressData=imread('../../data/barbara.png');
r=4;
N=2000;
temp=compressData;
trainImg=titan_build_train(temp,r,N);

opts.patchSize=[r,r];
opts.numAtoms=r*r;
opts.lambda=30;
opts.maxIter=200;
[dict,recImg,ratio]=nenya_train(trainImg,opts);
psnr(trainImg,recImg)
ratio
resImg=trainImg-recImg;
L1=sum(abs(resImg(:)))