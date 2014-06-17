img=imread('../../data/barbara.png');
img=double(img)/255.0;
st=tfdec2(img,dict,'sym',2);
rimg=tfrec2(st);
imshow(rimg,[])
%%
recImg=mtfrec2_imp(st);
imshow(recImg,[])
%%
st2=mtfdec2_imp(img,dict,1,2);
rimg2=mtfrec2_imp(st2);
imshow(rimg2,[])