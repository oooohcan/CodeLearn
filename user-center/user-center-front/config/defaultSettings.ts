import { Settings as LayoutSettings } from '@ant-design/pro-components';

const Settings: LayoutSettings & {
  pwa?: boolean;
  logo?: string;
} = {
  navTheme: 'light',
  // 青绿
  primaryColor: '#13C2C2',
  layout: 'top',
  contentWidth: 'Fixed',
  fixedHeader: false,
  fixSiderbar: true,
  colorWeak: false,
  title: 'XY Zoom',
  pwa: false,
  logo: 'logo.png',
  iconfontUrl: '',
};

export default Settings;

