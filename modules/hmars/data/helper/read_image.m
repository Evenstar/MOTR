srcFiles=dir('./*.jpg');
imgSize=zeros(length(srcFiles),2);
tic
CImages=zeros(200,200,160);
for i=1:160
    fname=strcat('./',srcFiles(i).name);
    I=double(rgb2gray(imread(fname)));
    I=imresize(I,[200,200]);
    CImages(:,:,i)=I;
end
toc