m=400;
n=400;
x=1:m;
y=1:n;
z=zeros(length(x),length(y));
[x,y]=meshgrid(x,y);
[theta,r]=cart2pol(x-floor(m/2),y-floor(n/2));
a=-0.5*exp(-r.^2/m/50);
u=a.*(x-floor(m/2));
v=a.*(y-floor(n/2));

subplot(1,2,1);
mesh(x,y,z);
axis([-1 1 -1 1 -1 1]);
axis equal
colormap hsv
view([0,0,1]);

x=1:400;
y=1:400;
[x,y]=meshgrid(x,y);
subplot(1,2,2);
mesh(x-u,y-v,z);
axis([-1 1 -1 1 -1 1]);
axis equal
view([0,0,1])

%%
I=double(imread('emma.jpg'))/255;
dimg=zeros(size(I));
for i=1:3
    dimg(:,:,i)=interp2(x,y,I(:,:,i),x+u,y+v);
end
subplot(1,2,1);
imshow(I);
subplot(1,2,2);
imshow(dimg)
%%
I=double(imread('emma.jpg'))/255;
scale=1.2;
angle=10*pi/180;
tx=0;
ty=0;
sc=scale*cos(angle);
ss=scale*sin(angle);
T=[sc -ss; ss, sc; tx ty];
t_nonsim=maketform('affine',T);
I_sim=imtransform(I,t_nonsim,'FillValues',1);
figure;
imshow(I_sim);

%%
[nrows,ncols] = size(I);
[xi,yi] = meshgrid(1:ncols,1:nrows);
a1 = 15; % Try varying the amplitude of the sinusoids.
a2 = 3;
imid = round(size(I,2)/2); % Find index of middle element
u = xi + a1*sin(pi*xi/imid);
v = yi - a2*sin(pi*yi/imid);
tmap_B = cat(3,u,v);
resamp = makeresampler('linear','fill');
I_sinusoid = tformarray(I,[],resamp,[2 1],[1 2],[],tmap_B,.3);

figure, imshow(I_sinusoid)
title('sinusoid')

%%
xt = xi(:) - imid;
yt = yi(:) - imid;
[theta,r] = cart2pol(xt,yt);
a = .000001; % Try varying the amplitude of the cubic term.
s = r + a*r.^3;
[ut,vt] = pol2cart(theta,s);
u = reshape(ut,size(xi)) + imid;
v = reshape(vt,size(yi)) + imid;
tmap_B = cat(3,u,v);
I_barrel = tformarray(I,[],resamp,[2 1],[1 2],[],tmap_B,.3);

figure, imshow(I_barrel)
title('barrel')

%%
u = [ 0   6  -2]';
v = [ 0   3   5]';
x = [-1   0   4]';
y = [-1 -10   4]';
tform = maketform('affine',[u v],[x y]);
x=1:10;
y=1:10;
[X Y]=meshgrid(x,y);
[xm,ym]=tformfwd(tform,X,Y);

%%
% inverse mapping function
f = @(x, unused) fliplr(x);

% maketform arguments
ndims_in = 2;
ndims_out = 2;
forward_mapping = [];
inverse_mapping = f;
tdata = [];
tform = maketform('custom', ndims_in, ndims_out, ...
    forward_mapping, inverse_mapping, tdata);


body2=imtransform(I,tform);
subplot(1,2,1)
imshow(I)
subplot(1,2,2)
imshow(body2)
%%
r = @(x) norm(x,2)
w = @(x) atan2(x(:,2),x(:,1));
f = @(x) [r(x).*cos(w(x)), r(x).*sin(w(x))];
g = @(x, unused) f(x)

tform2=maketform('custom', 2,2,[],g,[]);
I2=imtransform(I,tform2);
imshow(I2)


%%
r = @(x) sqrt(x(:,1).^2 + x(:,2).^2);
w = @(x) atan2(x(:,2), x(:,1));
f = @(x) [(r(x)).^2 .* cos(w(x)), (r(x)).^2 .* sin(w(x))];
g = @(x, unused) f(x);

tform2 = maketform('custom', 2, 2, [], g, []);
face2 = imtransform(I, tform2, 'UData', [-1 1], 'VData', [-1 1], ...
    'XData', [-1 1], 'YData', [-1 1]);
imshow(face2)

%%
x=linspace(-1,1,100);
y=linspace(-1,1,100);
z=zeros(length(x),length(y));
[x,y]=meshgrid(x,y);
[u,v]=tforminv(tform2,x,y);
surface(u,v,z);
colormap hsv
view([0,0,1]);
%%
g = @(x, unused) func(x);
tform2 = maketform('custom', 2, 2, [], g, []);
face2 = imtransform(I, tform2, 'UData', [-1 1], 'VData', [-1 1], ...
    'XData', [-1 1], 'YData', [-1 1]);
subplot(2,1,1);
imshow(I);
subplot(2,1,2);
imshow(face2)



















