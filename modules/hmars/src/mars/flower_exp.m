load ('../../data/oxfordflower/flower160.mat');
compressData=double(CImages);
r=8;
N=20000;
temp=compressData;
trainImg=titan_build_train(temp,r,N);

opts.patchSize=[r,r];
opts.numAtoms=10;
opts.lambda=10;
opts.maxIter=200;
[dict,recImg,ratio]=nenya_train(trainImg,opts);
dict=sortdict(dict);
psnr(trainImg,recImg)
ratio
resImg=trainImg-recImg;
L1=sum(abs(resImg(:)))
%%

%%
for i=1:1
    for j=1:5
        subplot(3,4,(i-1)*5+j);
        surface(reshape(dict((i-1)*5+j,:),r,r),'FaceColor','interp','EdgeColor','none','FaceLighting','phong');view(90,90)        
        xlim([1,7]),
        ylim([1,7]);
        
        grid off;
        axis off;
    end
end
%%
L=4;
m=size(dict,1);
img=CImages(:,:,1);
st=wtfdec2(img,dict,L,2);
for l=1:L
    for i=1:m
    [result, ~]=maxpooling(st.coef{l}{i},2,2);
    st.coef{l}{i}=result;
    end
end
%%
L=3;
m=size(dict,1);
st=wtfdec2(img,dict,L,2);
for l=1:L
    for i=1:m
        l,i
        if l~=L || i~=1
                [result, ~]=maxpooling(st.coef{l}{i},2,2);
  %  st.coef{l}{i}=result;
        end
    end
end
rimg=wtfrec2(st);
rimg=(rimg-min(rimg(:)))./(max(rimg(:))-min(rimg(:)))*255;
psnr(img,rimg)
%%
close
spy(abs(st.coef{3}{2})>0.5)








