function [out]=func(in)
x=in(:,1);
y=in(:,2);
dx=x;
dy=y;
for i=1:length(x)
    if (x(i)>0.1 && x(i)<0.95)
    dx(i)=x(i)-0.05;
    end
    if (x(i)<0.1)
        dx(i)=0.5*x(i);
    end
    if (x(i)>0.95)
        dx(i)=2*(x(i)-0.95)+0.9;
    end
end
out=[dx dy];