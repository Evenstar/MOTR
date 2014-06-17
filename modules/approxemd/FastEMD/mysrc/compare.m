function []=compare(i,j,data)
figure(1);
imshow(transpose(reshape(data(i,:),[28,28])),[])
figure(2);
imshow(transpose(reshape(data(j,:),[28,28])),[])
end